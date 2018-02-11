from .SJTU_crawler import SJTUNews

class TestSJTUNews(object):
    def test_get_news(self):
        SJTUNews.get_news()