# -*- coding:utf-8 -*-
import os

import random

# 杆


class Pole:
    def _init_(self, len_):
        slef.length = len_

    def getLength(self):
        return length

# 蚂蚁


class Ant:
    def _init_(self, name_, speed_, direction_, pos_):
        self.name = name_
        self.speed = speed_
        self.direction = direction_
        self.pos = pos_

    def getName(self):
        return name

    def getSpeed(self):
        return speed

    def getDirection(self):
        return direction

    def getPos(self):
        return pos

# 不满足is a 的关系


class Result:
    def _init_(self, ants_, pole_):
        self.ants = ants_
        self.ploe = pole_

    def getShortestTime(self):
        min_time = 0
        for item in ants:
            if item.getPos() < pole.getLength() / 2:
                cur_min = item.getPos() / item.getSpeed()
            else:
                cur_min = (pole.getLength() - item.getPos()) / item.getSpeed()
            if cur_min < min_time:
                min_time = cur_min
        return min

    def getLongestTime(self):
        max_time = 0
        for item in ants:
            if item.getPos() < pole.getLength() / 2:
                cur_max = (pole.getLength() - item.getPos()) / item.getSpeed()
            else:
                cur_max = item.getPos() / item.getSpeed()

            if cur_max > max_time:
                max_time = cur_max
        return max

    def getOrderTime(self):
        orderTime = [ants.len()]
        for item in ants:
            if item.getDirection() < 0:
                orderTime[ants.index(item)] = item.getPos()/item.getSpeed()
            else:
                orderTime[ants.index(
                    item)] = - ((pole.getLength() - item.getPos()) / item.getSpeed())

        orderTime.sort(lambda a, b: abs(a) < abs(b))

        return orderTime

    def getOrderNames(self):
        time = self.getOrderTime()
        head = 1
        tail = ants.len()
        oredrNames = []
        ants.sort(lambda a, b: a.pos < a.pos)
        for i in range(len(ants)):
            if time[i] < 0:
                oredrNames.append(ants[i].name)
                tail = tail-1
            else:
                oredrNames.append(ants[i].name)
                head = head + 1

        return oredrNames


# 时间不多，暂不考虑很多的异常输入，但考虑程序的对象组织。
pole_len = raw_input(" 请输入杆的长度(单位 厘米,蚂蚁默认爬完全部花费2分钟): ")

# 以毫米，秒为单位
sp = ((int)pole_len * 10) / 120
ants = []
ants_num = raw_input(" 请输入有多少只蚂蚁: ")
for it in range(1, ants_num):
    name = raw_input(" 请输入第 " + it + "只蚂蚁的名字: ")
    pos = random.randint(0, pole_len * 10)
    dire = random.randint(-1, 1)
    ant = Ant(name, sp, dire, pos)
    ants.append(ant)

res = Result(ants, Pole(pole_len))

print res.getLongestTime()
print res.getShortestTime()
print res.getOrderTime()
print res.getOrderNames()
