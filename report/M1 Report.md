# M1 Report

>**b0g队**
>
>3200105948 丁静怡
>
>3200105453 曹田雨



## Ch1 选题介绍

### 1.1 项目简介

我们选择的题目是制作MUD游戏。

我们计划用C++实现一个简单的迷宫游戏。开始游戏时可随机生成迷宫。玩家**需通过上下左右移动走出迷宫，同时保证到达终点前血量 > 0**。迷宫中存在魔龙、爆破枪、能量胶囊等NPC和随机掉落的装备，他们可对玩家血量造成影响。



### 1.2 计划实现功能

1. **构造新迷宫**：先把图变成全障碍，随机产生一条从入口到出口的路径，随机产生多条死路，去除多余障碍同时保证图的最短路长度不变；

2. **魔龙**：在迷宫内随机投放魔龙，魔龙可在小范围内自由移动，玩家需避开魔龙，否则血值-1；

3. **爆破枪**：迷宫内随机投放，存在时间10s，捡拾爆破枪后可放入背包，只能使用一次，使用一次爆破枪可以消灭一条魔龙；

4. **能量胶囊**：迷宫内随机投放，胶囊存在时间为10s，捡拾胶囊可血值+1；

5. **玩家**：玩家从入口进入迷宫，初始血值2。遇到魔龙血值-1，拾取胶囊血值+1,。血值为零则游戏自动结束。若成功到达出口，则游戏成功；

6. **等级设置**：游戏根据魔龙投放位置，迷宫复杂度可分为初级、中级、高级三个等级。



## Ch2 技术实现

我们将使用C++实现这个小游戏。以下是我们可能用到的相关知识和技术：

- 类（class）
  - 继承：我们可以通过类的继承来减少代码冗余；
  - 多态：成员方法和构造方法的重载；
  - 封装：将代码封装为类，隐藏其内部实现细节，仅保留外部接口，使代码简洁且便于维护内部数据；封装后**public**部分可以在类的内部和外界访问及调用；**private**部分只能在类的内部被访问跟调用。

- STL：在储存游戏数据时，我们可能会用到map，vector等模板库。

- 友元（friend）：当我们需要实现两个类之间的相互访问时，需要用到友元。



## Ch3 进度安排

#### 第一个月

搭建迷宫，设计地图类，并实现最基本的迷宫功能。

#### 第二个月

在原始迷宫基础上，实现NPC及装备功能，并增加“血量”判定条件。



