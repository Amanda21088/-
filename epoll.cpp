epoll 初识
按照哦man手册的说法，是为了处理大批量的句柄而做了改进的epoll
它几乎具备了之前多说的一切优点
被公认Linux2.6下性能最好的多路I / O就绪通知方法。
epoll 的相关系统调用
epoll_create
int epoll_create(int size)
1
建立epoll 模型：

红黑树
就绪队列
回调机制
epoll_ctl（对红黑树进行操作）
int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event)
1
epoll的事件注册函数：

它不同于select()是在监听事件时告诉内核要监听什么类型的事件，而是在这里先注册要监听的事件类型
第一个参数是epoll_create()的返回值
第二个参数表示动作，用三个宏来表示
第三个参数是需要监听的fd
第四个参数是告诉内核需要监听什么事
第二个参数的取值：

[EPOLL_CTL_ADD]：注册新的fd到epfd中；
[EPOLL_CTL_MOD]：修改已经注册的fd的监听事件
[EPOLL_CTL_DEL]：从epfd中删除一个fd
struct epoll_event结构如下：

	typedef union epoll_data
{
		void *ptr;
		int fd;
		unit32_t u32;//事件存放的位置
		unit64_t u64;
	}epoll_data_t;

struct epoll_event
{
	unit32_t events; //epoll events
	epoll_data_t data; //user data variable
}__EPOLL_PACKED
1
2
3
4
5
6
7
8
9
10
11
12
13
events可以是以下几个宏的集合（列举出常用的几个）：

EPOLLIN：表示对应的文件描述符可以读
EPOLLOUT：表示对应的文件描述符可以写
EPOLLET：将epoll设置为边缘触发
epoll_wait（获取有多少个文件描述符就绪）
int epoll_wait(int epfd, struct epoll_event *events, int maxevent, int timeout);
//内核->用户，内核告诉用户哪些文件描述符上的事件已经就绪
1
2
收集在epoll监控的事件中已经发送的事件。

参数 events是分配好的epoll_event结构体数组。
epoll 将会把发生的事件赋值到events数组中
maxevents告诉内核这个events有多大，这个maxevents的值不能大于创建epoll_create()时的size
参数timeout是超时时间
如果函数调用成功，返回对应的I / O上已准备好的文件描述符数目，如果0表示已超时，返回小于0表示函数失败
无论有多少文件描述符，时间复杂度都是O(1)，不用轮询查找，将所有就绪事件全部展示给用户
总结一下，epoll的使用过程就是一个三部曲：
调用epoll_create()，创建一个epoll句柄
调用epoll_ctl()，将要监控的文件描述符进行注册
调用epoll_wait()，等待文件描述符就绪
epoll的优点（和select的缺点对应）
接口使用方便： 虽然拆分成三个函数进行（即三部曲），但是反而使用起来更方便高效。不需要每次循环都设置关注的文件描述符，也做到了输入输出参数分离。
数据拷贝轻量： 只在合适的时候调用EPOLL_CTL_ADD将文件描述符结构拷贝到内核中，这个操作并不频繁（而select和poll都是每次循环都要进行拷贝）
事件回调机制： 避免使用遍历，而是使用回调函数的方式，将就绪事件的文件描述符加入到就绪队列中，epoll_wait 返回直接访问就绪队列就知道哪些文件描述符就绪。这个操作的时间复杂度是O(1)，即使文件描述符的数目很多，效率也不会受到影响。
没有数量限制： 文件描述符数目无上限
epoll的工作方式
你妈喊你回家吃饭的例子

你正在吃鸡，眼看进入了决赛圈，你妈饭做好了，喊你吃饭的时候有两种方式：

如果你妈喊你一次，你没动，那么你妈会继续喊你第二次，第三次…（亲妈，水平触发）LT
如果你妈喊你一次，你没动，你妈就不管你了（后妈，边缘触发）ET
epoll有2中工作方式：水平触发（LT）和边缘触发（ET）

假如有这样的例子：

我们已经把一个tcp socket添加到epoll描述符
这个时候socket的另一端被写入2KB的数据
调用epoll_wait，并且它会返回，说明它已经准备好读取操作
然后调用read，只读取1KB的数据
继续调用epoll_wait…
水平触发工作模式
epoll默认状态下就是LT工作模式

当epoll检测到socket上事件就绪的时候, 可以不立刻进行处理.或者只处理一部分.
如上面的例子, 由于只读了1K数据, 缓冲区中还剩1K数据, 在第二次调用 epoll_wait 时, epoll_wait 仍然会立刻返回并通知socket读事件就绪.
直到缓冲区上所有的数据都被处理完, epoll_wait 才不会立刻返回.
支持阻塞读写和非阻塞读写
边缘触发工作模式
如果我们在第1步将socket添加到epoll描述符的时候使用了EPOLLET标志, epoll进入ET工作模式.

当epoll检测到socket上事件就绪时, 必须立刻处理.
如上面的例子, 虽然只读了1K的数据, 缓冲区还剩1K的数据, 在第二次调用 epoll_wait 的时候, epoll_wait 不会再返回了.
也就是说, ET模式下, 文件描述符上的事件就绪后, 只有一次处理机会.ET的性能比LT性能更高(epoll_wait 返回的次数少了很多).Nginx默认采用ET模式使用epoll.
只支持非阻塞的读写
使用ET模式的epoll，需要将文件描述符设置成非阻塞
select 和 poll其实也是工作在LT模式下。epoll 既可以支持LT，也支持ET。

对比LT和ET
LT是 epoll 的默认行为.使用 ET 能够减少 epoll 触发的次数.但是代价就是强逼着程序猿一次响应就绪过程中就把 所有的数据都处理完.

相当于一个文件描述符就绪之后, 不会反复被提示就绪, 看起来就比 LT 更高效一些.但是在 LT 情况下如果也能做到 每次就绪的文件描述符都立刻处理, 不让这个就绪被重复提示的话, 其实性能也是一样的.

另一方面, ET 的代码复杂程度更高了。

epoll的使用场景
epoll的高性能, 是有一定的特定场景的.如果场景选择的不适宜, epoll的性能可能适得其反.

对于多连接，且多连接中只有一部分连接比较活跃时，比较适合epoll。

例如, ：
典型的一个需要处理上万个客户端的服务器, 例如各种互联网APP的入口服务器, 这样的服务器就很适合epoll.如果只是系统内部, 服务器和服务器之间进行通信, 只有少数的几个连接, 这种情况下用epoll就并不合适.具体要根 据需求和场景特点来决定使用哪种IO模型


