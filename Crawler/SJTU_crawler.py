from bs4 import BeautifulSoup
import requests
# import codecs
# import smtplib
# from email.mime.text import MIMEText
# import time

class SJTUNews():
    def __init__(self):
        self.NewsList = []

    def get_news():
        url = 'http://electsys.sjtu.edu.cn/edu/'
        r = requests.get(url)
        soup = BeautifulSoup(r.text, 'html.parser')
        newsClass = soup.find_all('a', 'news')
        newsTitle = []
        for item in newsClass:
            title_raw = str(item.string)
            title = title_raw.strip()
            newsTitle.append(title)
            if title != 'None':
                print(title)

        # print(newsTitle)


if __name__ == '__main__':
    SJTUNews.get_news()