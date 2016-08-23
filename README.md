#五子棋对战小游戏
#介绍
支持多人对战，由于游戏性质，使用典型的同步阻塞IO模型，多进程提供服务
#运行环境
项目运行在linux系统上 
#安装
在linux系统下可以直接将下载的项目解压，然后执行以下两个命令
```bash
make -f makefile_server
make -f makefile_client

```
#使用方法
安装完毕后，执行一下命令就可以启动该项目
```bash
./bin/server
./bin/client
```
启动该项目后将会展现如下的界面，然后就可以五子棋对战啦


