#from test_user_class import user
import test_user_class

if __name__ == '__main__':
	a = test_user_class.user("cheng",25, 150)
	print a.name
	a.speak()
	b = test_user_class.vip_user("shao",30,160,10)
	b.speak()
