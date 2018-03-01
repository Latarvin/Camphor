import urllib.request
import urllib.parse
import random

LENGTH_DEFAULT = 500
WIDTH_DEFAULT = 600
URL_BASE = 'http://placekitten.com'
# URL_BASE = 'http://placekitten.com/g'  # grey image


def get_para():
    para = {}
    while True:
        for item in ['length', 'width']:
            para[item] = random.randrange(10, 1000, 50)

        if para['length'] == para['width']:
            continue
        else:
            return para


def get_cat_img(length=LENGTH_DEFAULT, width=WIDTH_DEFAULT):
    url = '{url_base}/{length}/{width}'.format(url_base=URL_BASE, length=length, width=width)
    response = urllib.request.urlopen(url)
    cat_img = response.read()

    with open('cat_{length}_{width}.jpg'.format(length=length, width=width), 'wb') as f:
        f.write(cat_img)


def main():
    para = get_para()
    get_cat_img(para['length'], para['width'])


if __name__ == '__main__':
    main()