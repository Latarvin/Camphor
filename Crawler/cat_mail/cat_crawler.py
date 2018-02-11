import urllib.request
import urllib.parse
import json


class crawler(object):
    def get_SJTU_content():
        SJTU_URL = 'http://electsys.sjtu.edu.cn/edu/'
        response = urllib.request.urlopen(SJTU_URL)
        html = response.read()
        html = html.decode('utf-8')
        print(html)

    def get_cat():
        URL_BASE = 'http://placekitten.com'
        # URL_BASE = 'http://placekitten.com/g'
        length = 500
        width = 600
        url = '{url_base}/{length}/{width}'.format(url_base=URL_BASE, length=length, width=width)
        response = urllib.request.urlopen(url)
        cat_img = response.read()

        with open('cat_{length}_{width}.jpg'.format(length=length, width=width), 'wb') as f:
            f.write(cat_img)

    def get_translation():
        url = 'http://fanyi.youdao.com/translate_o?smartresult=dict&smartresult=rule'

        # header = {}
        # header['User-Agent'] = 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko)' \
        #                        ' Chrome/61.0.3163.100 Safari/537.36'

        data = {}
        data['i'] = 'I don\'t know'
        data['smartresult'] = 'dict'
        data['client'] = 'fanyideskweb'
        data['doctype'] = 'json'
        data['version'] = '2.1'
        data['keyfrom'] = 'fanyi.web'
        data['typoResult'] = 'false'
        data = urllib.parse.urlencode(data).encode('utf-8')

        response = urllib.request.urlopen(url, data)
        html = response.read().decode('utf-8')
        print(html)
        target = json.load(html)

if __name__ == '__main__':
    # crawler.get_cat()
    crawler.get_translation()