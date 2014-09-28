import unittest

class Hello(unittest.TestCase):
    def test_x(self):
        assert 1==1
    def test_a(self):
        assert 1==1
    def test_b(self):
        assert 1==3
    def test_c(self):
        assert 1==1

unittest.main()
