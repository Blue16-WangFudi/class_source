#吐槽一下：我不会写那么无聊的程序，但是当成一个登录验证的实例还是可以，主要是帮同学改代码。

#建议使用哈希表，优化查找速度
userlist=[['xiaolu','5201314'],['lingyueqing','1314520']]
print('---------------------欢迎登录顾易的世界---------------------')
import random
turnte = random.randint(1000, 9999)
print('本次登录的验证码：', turnte)
name = input('用户名：')
key = input('密码:')
testbot = input("验证码：")
i = 0
###测试（已经不对！！！）
#使用for循环应该会更快，占用空间更少。因为不需要重新构建list，按照你的思路，那就构造一个list进行查询。
searchlist=[name,key]

#in语句返回的是bool类型，可以写在一起
if (searchlist in userlist) and turnte == int(testbot):#userlist[0][0]代表的一个固定的人名，是不是只有一个人名能登录我不知道是不是你刻意设计的。
    print('欢迎宝宝~')


'''while i <= (len(userlist)+1):
    print(i)
    if name in userlist[i][0]:
        if key is userlist[i][1]:
            if turnte == testbot:
                print('欢迎宝宝~')
            elif i <= (len(userlist)):
                i += 1
            else:
                print('验证码错误！')
        elif i <= (len(userlist)):
            i += 1
        else:
            print('密码错误')
    elif i <= (len(userlist)):
        i += 1
    else:
        print('账号错误',i)

'''