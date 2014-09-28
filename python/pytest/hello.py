#import pytest

print "Hello World"

def test_f():
    print "test fucntion"
    assert 1==0

class TestHello:
    def test_a(self):
        print "hello a"
        assert 1==1

    def b(self):
        print "hello b"

#pytest.main("-v")
