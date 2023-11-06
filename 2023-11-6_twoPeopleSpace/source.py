'''模拟系统登录。建立一个用户信息列表，内部存有若干组用户名和密码。随机生成一个
4 位数验证码，用户从键盘依次输入用户名、密码和验证码，将用户输入的结果和用户
信息列表以及校验码进行比较，如果用户名和密码不正确则输出提示“用户名或密码不
正确”，如果验证码不正确则提示“验证码有误”，如果全部正确提示“登录成功”。'''

userlist=[['xiaolu',5201314],['lingyueqing',1314520]]
print('---------------------欢迎登录顾易的世界---------------------')
import random
turnte = random.randint(1000, 9999)
print('本次登录的验证码：', turnte)
name = input('用户名：')
key = input('密码:')
testbot = input("验证码：")
i = 0
###测试（已经不对！！！）
if name in userlist[0][0]:
    if key == userlist[0][1]:
        if turnte == testbot:
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
