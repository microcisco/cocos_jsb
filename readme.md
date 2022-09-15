### cocos JS和c++绑定
#### 绑定代码
主要在 jsb_cocos2dx_network_auto里面具体搜udp关键字
### 注意事项
* 执行js代码需要在cocos的ui线程
* 如果希望通过NativePtrToObjectMap方法找到对应的js对象必须绑定构造函数在构造函数里面执行setPrivateData
 函数来维护c++到js对象的映射表