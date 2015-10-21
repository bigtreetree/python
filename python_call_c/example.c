#include <stdio.h>
#include <Python.h>
//目标函数
int fact(int n)
{
	if (n <=1)
		return 1;
	else
		return n* fact(n-1);
}

//python包装

PyObject* wrap_fact(PyObject* self, PyObject* args)
{
	int n, result;
	if (!PyArg_ParseTuple(args,"i:fact",&n))//把python的变量转换成c的变量
		return NULL;
	result = fact(n);
	return Py_BuildValue("i",result);//把c的返回值n转换成python的对象
}

//方法列表
static PyMethodDef exampleMethods[]=
{
	{"fact",wrap_fact,METH_VARARGS,"Caculate N!"},
	{NULL, NULL}
};
//方法列表中的每项由四个部分组成：方法名，导出函数，参数传递方式和
//方法描述。方法名是从python解释器中调用该方法时所使用的名字。参数传递方法
//则规定了python向c函数传递参数的具体形式，可选的两种方式是ＭＥＴＨ——ＶＡＲＡＲＧＳ和
//ＭＥＴＨ—ＫＥＹＷＯＲＤＳ，其中ＭＥＴＨ——ＶＡＲＡＲＧＳ是参数传递的标准形式，它通过
//python的元组在python解释器和c函数之间传递参数，若彩METH_KEYWORD方式，则python解释器
//和c函数之间将通过python的字典类型在两者之间进行参数传递.

//初始化函数
PyMODINIT_FUNC initexample()
{
	PyObject* m;
	m = Py_InitModule("example", exampleMethods);
}
//所有的python扩展模块都必须要有一个初始化函数，以便python解释器能够对
//模块进行正确的初始化。python解释器规定所有的初始化函数的函数名都必须以init
//形状，并加上模块的名字.对于模块example来说，则相关的初始化函数为




