#include "scripting/js-bindings/auto/jsb_cocos2dx_network_auto.hpp"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "network/CCDownloader.h"
#include <thread>
#include "../../../cocos/platform/CCApplication.h"
#include "../../../cocos/base/CCScheduler.h"

se::Object* __jsb_cocos2d_network_Downloader_proto = nullptr;
se::Class* __jsb_cocos2d_network_Downloader_class = nullptr;

se::Object* __jsb_cocos2d_network_udp_proto = nullptr;
se::Class* __jsb_cocos2d_network_udp_class = nullptr;


static bool js_network_Downloader_setOnTaskProgress(se::State& s)
{
    cocos2d::network::Downloader* cobj = (cocos2d::network::Downloader*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_network_Downloader_setOnTaskProgress : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::function<void (const cocos2d::network::DownloadTask &, long long, long long, long long)> arg0;
        do {
            if (args[0].isObject() && args[0].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject());
                se::Value jsFunc(args[0]);
                jsThis.toObject()->attachObject(jsFunc.toObject());
                auto lambda = [=](const cocos2d::network::DownloadTask & larg0, long long larg1, long long larg2, long long larg3) -> void {
                    se::ScriptEngine::getInstance()->clearException();
                    se::AutoHandleScope hs;
        
                    CC_UNUSED bool ok = true;
                    se::ValueArray args;
                    args.resize(4);
                    ok &= DownloadTask_to_seval(larg0, &args[0]);
                    ok &= longlong_to_seval(larg1, &args[1]);
                    ok &= longlong_to_seval(larg2, &args[2]);
                    ok &= longlong_to_seval(larg3, &args[3]);
                    se::Value rval;
                    se::Object* thisObj = jsThis.isObject() ? jsThis.toObject() : nullptr;
                    se::Object* funcObj = jsFunc.toObject();
                    bool succeed = funcObj->call(args, thisObj, &rval);
                    if (!succeed) {
                        se::ScriptEngine::getInstance()->clearException();
                    }
                };
                arg0 = lambda;
            }
            else
            {
                arg0 = nullptr;
            }
        } while(false)
        ;
        SE_PRECONDITION2(ok, false, "js_network_Downloader_setOnTaskProgress : Error processing arguments");
        cobj->setOnTaskProgress(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_network_Downloader_setOnTaskProgress)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_network_Downloader_finalize)

static bool js_network_Downloader_constructor(se::State& s)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 1) {
            cocos2d::network::DownloaderHints arg0;
            ok &= seval_to_DownloaderHints(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::network::Downloader* cobj = new (std::nothrow) cocos2d::network::Downloader(arg0);
            s.thisObject()->setPrivateData(cobj);
            se::NonRefNativePtrCreatedByCtorMap::emplace(cobj);
            return true;
        }
    } while(false);
    do {
        if (argc == 0) {
            cocos2d::network::Downloader* cobj = new (std::nothrow) cocos2d::network::Downloader();
            s.thisObject()->setPrivateData(cobj);
            se::NonRefNativePtrCreatedByCtorMap::emplace(cobj);
            return true;
        }
    } while(false);
    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_CTOR(js_network_Downloader_constructor, __jsb_cocos2d_network_Downloader_class, js_cocos2d_network_Downloader_finalize)



static bool js_cocos2d_network_udp_finalize(se::State& s)
{
	CCLOGINFO("jsbindings: finalizing JS object %p (cocos2d::network::Downloader)", s.nativeThisObject());
	auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
	if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
	{
		se::NonRefNativePtrCreatedByCtorMap::erase(iter);
		cocos2d::network::udp* cobj = (cocos2d::network::udp*)s.nativeThisObject();
		delete cobj;
	}
	return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_network_udp_finalize)

static bool js_cocos2dx_network_udp_constructor(se::State& s)
{
	cocos2d::network::udp* cobj = new (std::nothrow) cocos2d::network::udp();
	s.thisObject()->setPrivateData(cobj);
	return true;
}
SE_BIND_CTOR(js_cocos2dx_network_udp_constructor, __jsb_cocos2d_network_udp_class, js_cocos2d_network_udp_finalize);


static bool js_cocos2dx_network_udp_send(se::State &s) { // 方法名与声明时一致
	cocos2d::network::udp *cobj = (cocos2d::network::udp *) s.nativeThisObject();
	SE_PRECONDITION2(cobj, false,
		"js_cocos2dx_network_udp_send : Invalid Native Object");
	const auto &args = s.args();
	size_t argc = args.size();
	CC_UNUSED bool ok = true;
	if (argc == 3) {
	
		std::string url;
		int port;
		ok &= seval_to_std_string(args[0], &url); // 转化为std::string url
		ok &= seval_to_int32(args[1], &port); // 转化为std::string path
		std::function<void(const std::string& msg,
			const int code)> callback;


		se::Value jsThis(s.thisObject());
		se::Value jsFunc(args[2]);
		se::Object* thisObj = jsThis.isObject() ? jsThis.toObject() : nullptr;
		se::Object* funcObj = jsFunc.toObject();
		se::Value rval;
		bool succeed = funcObj->call(args, thisObj, &rval);
		if (!succeed) {
			se::ScriptEngine::getInstance()->clearException();
		}

		auto iter = se::NativePtrToObjectMap::find(cobj);

		if (iter == se::NativePtrToObjectMap::end())
			return false;

		std::thread([=]() {
			while (true)
			{
				Sleep(1000);
				cocos2d::Application::getInstance()->getScheduler()->performFunctionInCocosThread([=] {
					//se::ScriptEngine::getInstance()->evalString("window.b('jaja',8)");


					se::ScriptEngine::getInstance()->clearException();
					se::AutoHandleScope hs;

					if (cocos2d::Application::getInstance() == nullptr)
						return;

					auto iter = se::NativePtrToObjectMap::find(cobj);

					if (iter == se::NativePtrToObjectMap::end())
						return;

					se::Object* wsObj = iter->second;
					se::Value func;
					bool ok = wsObj->getProperty("onmessage", &func);
					if (ok && func.isObject() && func.toObject()->isFunction())
					{
						se::ValueArray v;
						v.resize(2);
						v[0] = se::Value("xiaoxi1");
						v[1] = se::Value(23);
						func.toObject()->call(v, wsObj);
					}
					else
					{
						SE_REPORT_ERROR("Can't get onmessage function!");
					}


				});
			}
			

		}).detach();


		return true;
	}
	SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
	return false;
}

SE_BIND_FUNC(js_cocos2dx_network_udp_send); // 包装该方法

bool js_register_cocos2dx_network_udp(se::Object* obj) {

	auto cls = se::Class::create("udp", obj, nullptr, _SE(js_cocos2dx_network_udp_constructor));
	cls->defineFunction("send", _SE(js_cocos2dx_network_udp_send));
	cls->install();
	__jsb_cocos2d_network_udp_class = cls;
	__jsb_cocos2d_network_udp_proto = cls->getProto();
	JSBClassType::registerClass<cocos2d::network::udp>(cls);
	se::ScriptEngine::getInstance()->clearException();
	return true;
}




static bool js_cocos2d_network_Downloader_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (cocos2d::network::Downloader)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        cocos2d::network::Downloader* cobj = (cocos2d::network::Downloader*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_network_Downloader_finalize)

bool js_register_network_Downloader(se::Object* obj)
{
    auto cls = se::Class::create("Downloader", obj, nullptr, _SE(js_network_Downloader_constructor));

    cls->defineFunction("setOnTaskProgress", _SE(js_network_Downloader_setOnTaskProgress));
    cls->defineFinalizeFunction(_SE(js_cocos2d_network_Downloader_finalize));
    cls->install();
    JSBClassType::registerClass<cocos2d::network::Downloader>(cls);

    __jsb_cocos2d_network_Downloader_proto = cls->getProto();
    __jsb_cocos2d_network_Downloader_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

bool register_all_network(se::Object* obj)
{
    // Get the ns
    se::Value nsVal;
    if (!obj->getProperty("jsb", &nsVal))
    {
        se::HandleObject jsobj(se::Object::createPlainObject());
        nsVal.setObject(jsobj);
        obj->setProperty("jsb", nsVal);
    }
    se::Object* ns = nsVal.toObject();

    js_register_network_Downloader(ns);

	js_register_cocos2dx_network_udp(ns);
    return true;
}

#endif //#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
