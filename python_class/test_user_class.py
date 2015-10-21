#coding=utf-8
#定义一个类
class user:
	name=''
	age=0      #公有属性,可以在类的外部直接访问
	__weight=0 #私有属性，不能在类的外部被直接访问，在类内部的方法中使用self.__weight来访问
	def __init__(self, n,a,w): #构造函数
		print("constructor")
		self.name = n
		self.age = a
		self.__weight = w	
	def __del__(self):#析构函数
		print("destroy constructor");
	def speak(self): 	#公有方法	
		self.__speak_impl()#注意调用私有方法实现时，并没有把参数self传递过去
	def __speak_impl(self): #私有方法
		print("name:%s, age:%d,weight:%d"%(self.name, self.age, self.__weight))
	def getweight(self):
		return self.__weight;		

#单继承
class vip_user(user):
	__level=0
	def __init__(self, name, age, weight, level):
		#调用父类的构造函数	
		user.__init__(self, name, age, weight);
		self.__level = 1
	#覆盖父类的方法
	def speak(self):
	#即使是子类也无权限直接调用self._weight,
		print("name:%s,age:%d, weight:%d , level:%d" %(self.name, self.age, self.getweight(),self.__level));


	
