#include "IAMPluginFactory.h"
#include "IAMUtils.h"

using namespace Redshift::IamSupport;

////////////////////////////////////////////////////////////////////////////////////////////////////
std::unique_ptr<IAMPluginCredentialsProvider> IAMPluginFactory::CreatePlugin(
    const rs_wstring& in_pluginName,
    RsLogger* in_log,
    const IAMConfiguration& in_config,
    const std::map<rs_string, rs_string>& in_argsMap)
{
    RS_LOG(in_log)("IAMPluginFactory::CreatePlugin");

    std::unique_ptr<IAMPluginCredentialsProvider> credProvider;

    if (IAMUtils::isEqual(in_pluginName, IAMUtils::convertCharStringToWstring(IAM_PLUGIN_ADFS), false))
    {
        credProvider = CreateAdfsPlugin(in_log, in_config, in_argsMap);
    }
    else if (IAMUtils::isEqual(in_pluginName, IAMUtils::convertCharStringToWstring(IAM_PLUGIN_AZUREAD), false))
    {
        credProvider = CreateAzurePlugin(in_log, in_config, in_argsMap);
    }
    else if (IAMUtils::isEqual(in_pluginName, IAMUtils::convertCharStringToWstring(IAM_PLUGIN_BROWSER_AZURE), false))
    {
        credProvider = CreateBrowserAzurePlugin(in_log, in_config, in_argsMap);
    }
	else if (IAMUtils::isEqual(in_pluginName, IAMUtils::convertCharStringToWstring(IAM_PLUGIN_BROWSER_AZURE_OAUTH2), false))
	{
		credProvider = CreateBrowserAzureOAuth2Plugin(in_log, in_config, in_argsMap);
	}
	else if (IAMUtils::isEqual(in_pluginName, IAMUtils::convertCharStringToWstring(IAM_PLUGIN_BROWSER_SAML), false))
    {
        credProvider = CreateBrowserSamlPlugin(in_log, in_config, in_argsMap);
    }
    else if (IAMUtils::isEqual(in_pluginName, IAMUtils::convertCharStringToWstring(IAM_PLUGIN_PING), false))
    {
        credProvider = CreatePingPlugin(in_log, in_config, in_argsMap);
    }
    else if (IAMUtils::isEqual(in_pluginName, IAMUtils::convertCharStringToWstring(IAM_PLUGIN_OKTA), false))
    {
        credProvider = CreateOktaPlugin(in_log, in_config, in_argsMap);
    }
    else if (IAMUtils::isEqual(in_pluginName, IAMUtils::convertCharStringToWstring(IAM_PLUGIN_JWT), false))
    {
        credProvider = CreateJwtPlugin(in_log, in_config, in_argsMap);
    }
    else
    {
        credProvider = CreateExternalPlugin(in_log, in_config, in_argsMap); // .Detach()
    }

    return credProvider;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
std::unique_ptr<IAMAdfsCredentialsProvider> IAMPluginFactory::CreateAdfsPlugin(
    RsLogger* in_log,
    const IAMConfiguration& in_config,
    const std::map<rs_string, rs_string>& in_argsMap)
{
    RS_LOG(in_log)("IAMPluginFactory::CreateAdfsPlugin");

    return std::unique_ptr<IAMAdfsCredentialsProvider>(
        new IAMAdfsCredentialsProvider(in_log, in_config, in_argsMap));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
std::unique_ptr<IAMAzureCredentialsProvider> IAMPluginFactory::CreateAzurePlugin(
    RsLogger* in_log,
    const IAMConfiguration& in_config,
    const std::map<rs_string, rs_string>& in_argsMap)
{
    RS_LOG(in_log)("IAMPluginFactory::CreateAzurePlugin");

    return std::unique_ptr<IAMAzureCredentialsProvider>(
        new IAMAzureCredentialsProvider(in_log, in_config, in_argsMap));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
std::unique_ptr<IAMBrowserAzureCredentialsProvider> IAMPluginFactory::CreateBrowserAzurePlugin(
    RsLogger* in_log,
    const IAMConfiguration& in_config,
    const std::map<rs_string, rs_string>& in_argsMap)
{
    RS_LOG(in_log)("IAMPluginFactory::CreateBrowserAzurePlugin");

    return std::unique_ptr<IAMBrowserAzureCredentialsProvider>(
        new IAMBrowserAzureCredentialsProvider(in_log, in_config, in_argsMap));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
std::unique_ptr<IAMBrowserAzureOAuth2CredentialsProvider> IAMPluginFactory::CreateBrowserAzureOAuth2Plugin(
	RsLogger* in_log,
	const IAMConfiguration& in_config,
	const std::map<rs_string, rs_string>& in_argsMap)
{
	RS_LOG(in_log)("IAMPluginFactory::CreateBrowserAzureOAuth2Plugin");

	return std::unique_ptr<IAMBrowserAzureOAuth2CredentialsProvider>(
		new IAMBrowserAzureOAuth2CredentialsProvider(in_log, in_config, in_argsMap));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
std::unique_ptr<IAMBrowserSamlCredentialsProvider> IAMPluginFactory::CreateBrowserSamlPlugin(
    RsLogger* in_log,
    const IAMConfiguration& in_config,
    const std::map<rs_string, rs_string>& in_argsMap)
{
    RS_LOG(in_log)("IAMPluginFactory::CreateBrowserSamlPlugin");

    return std::unique_ptr<IAMBrowserSamlCredentialsProvider>(
        new IAMBrowserSamlCredentialsProvider(in_log, in_config, in_argsMap));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
std::unique_ptr<IAMPingCredentialsProvider> IAMPluginFactory::CreatePingPlugin(
    RsLogger* in_log,
    const IAMConfiguration& in_config,
    const std::map<rs_string, rs_string>& in_argsMap)
{
    RS_LOG(in_log)("IAMPluginFactory::CreatePingPlugin");

    return std::unique_ptr<IAMPingCredentialsProvider>(
        new IAMPingCredentialsProvider(in_log, in_config, in_argsMap));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
std::unique_ptr<IAMOktaCredentialsProvider> IAMPluginFactory::CreateOktaPlugin(
    RsLogger* in_log,
    const IAMConfiguration& in_config,
    const std::map<rs_string, rs_string>& in_argsMap)
{
    RS_LOG(in_log)("IAMPluginFactory::CreateOktaPlugin");

    return std::unique_ptr<IAMOktaCredentialsProvider>(
        new IAMOktaCredentialsProvider(in_log, in_config, in_argsMap));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
std::unique_ptr<IAMJwtBasicCredentialsProvider> IAMPluginFactory::CreateJwtPlugin(
    RsLogger* in_log,
    const IAMConfiguration& in_config,
    const std::map<rs_string, rs_string>& in_argsMap)
{
    RS_LOG(in_log)("IAMPluginFactory::CreateJwtPlugin");

    return std::unique_ptr<IAMJwtBasicCredentialsProvider>(
        new IAMJwtBasicCredentialsProvider(in_log, in_config, in_argsMap));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
std::unique_ptr<IAMExternalCredentialsProvider> IAMPluginFactory::CreateExternalPlugin(
    RsLogger* in_log,
    const IAMConfiguration& in_config,
    const std::map<rs_string, rs_string>& in_argsMap)
{
    RS_LOG(in_log)("IAMPluginFactory::CreateExternalPlugin");

    return std::unique_ptr<IAMExternalCredentialsProvider>(
        new IAMExternalCredentialsProvider(in_log, in_config, in_argsMap));
}
