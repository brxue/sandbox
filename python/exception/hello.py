class MyException(RuntimeError):
    def __init__(self, *args):
        self.args = args

try:
    raise MyException({"message":"hello bad thing happens", "value":0xdeaddead}, "argument2")
except MyException as e:
    print e.args
    print e.args[0]["message"]
    print e.args[1]
