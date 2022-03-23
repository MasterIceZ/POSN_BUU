from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from webdriver_manager.firefox import GeckoDriverManager
import time
import shutil
import os

driver = webdriver.Firefox(executable_path=GeckoDriverManager().install())

driver.get("http://posn.buu.ac.th/login.php")

username = driver.find_element_by_id("id")
username.clear()
username.send_keys(input("Username : "))

password = driver.find_element_by_name("pass")
password.clear()
password.send_keys(input("Password : "))

driver.find_element_by_xpath("//input[@type='submit' and @value='Login']").click()

time.sleep(2)
ht = driver.page_source

s = ht.split("<td>")
s.remove(s[0])
s.remove(s[-1])

print(s)

a = []
for i in range(len(s)) :
    t = s[i].split("[")
    print(len(t))
    if len(t) >= 2 :
        t = t[1].split("]")[0]
        if t != 'compiler message' :
            a.append(t)

print(a)
driver.close()

di = input("New Directory : ")
pp = os.getcwd()
print(pp)
os.makedirs(pp + '/' + di)

path = pp + '/' + di + '/'

for x in a:
    shutil.copyfile("0.cpp", path + x + ".cpp")
