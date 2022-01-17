import string
import keyboard
import random
from selenium import webdriver

def randomLink():
    randomChar = string.ascii_lowercase
    randomInt = [0,1,2,3,4,5,6,7,8,9]
    link="https://prnt.sc/"
    for x in range(2):
        link += random.choice(randomChar)
    for i in range(4):
        link += str(random.choice(randomInt))
    return link
driver = webdriver.Chrome()
while True:
    link = randomLink()
    print(link+"\n")
    driver.get(link)
    keyboard.wait("f10")