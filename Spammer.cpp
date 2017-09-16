#include "Gamehooking.hpp"
#include "Spammer.hpp"

std::vector<std::string> msgs =
{
	"@_@",
};

void Spammer::spam()
{
	if (!p_Engine->isIG())
		return;

	long curTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	static long timestamp = curTime;

	if ((curTime - timestamp) < 850)
		return;

	if (mVars.bEnableSpam)
	{
		if (msgs.empty())
			return;

		srand(time(NULL));

		std::string msg = msgs[rand() % msgs.size()];

		std::string str;
		str.append("say ");
		str.append(msg);

		p_Engine->execClientCMD(str.c_str());
	}

	timestamp = curTime;
}
