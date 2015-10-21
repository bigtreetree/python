#include <stdio.h>

int PyCall(const char* module, const char* function, const char* format,...)
{
	PyObject* pMod = NULL;
	PyObject* pFunc = NULL;
	PyObject* pParm = NULL;
	PyObject* pRetVal = NULL;

	//导入模块
	if(!(pMod = PyImport_ImportModule(module))){
		return -1;
	}
	//查找函数
	if(!(pFunc = PyObject_GetAttrString(pMod, function))){
		return -2;
	}

	//创建参数
	va_list vargs;
	va_start(vargs, format);
	pParm = Py_VaBuildValue(format, vargs);
	va_end(vargs)
	//函数调用
	pRetVal = PyEval_CallObject(pFunc, pParm);
	//假定返回值为整形
	int ret;
	PyArg_Parse(pRetVal, "i", &ret);
	return ret;
}

int main(int argc, char*argv[])
{
	Py_Initialize();
	/*这做个简单的说明
	 * format参数用()括起来是表示元组的意思。元组中的个数对应python脚本中的参数
	 * 因为fun,
	 * fun1,fun2函数的参数个数分别是０，１，２所以，元组中的个数必须为０，１，２，
	 * 不然调用将失败。当然，元组中的每个元素都是可以为任意的类型，比如：
	 * 　PyCall("pytest,"func2", "
	 */
	printf("ret = %d\n",PyCall("pytest","fun","()");
	printf("ret = %d\n",PyCall("pytest","fun1","(i)",12);
	printf("ret = %d\n",PyCall("pytest","fun2","(is)",12,"12");
	Py_Finalize();
	return 0;
}
