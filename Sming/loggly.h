#ifndef __LOGGLY_H__
#define __LOGGLY_H__

#include <SmingCore/SmingCore.h>

#ifndef LOGGLY_HOST
	#define LOGGLY_HOST "logs-01.loggly.com"
#endif

#ifndef LOGGLY_KEY
	#define LOGGLY_KEY "client_key"
#endif

static const char * LOGGLY_URL_FORMAT = "http://%s/inputs/%s/tag/%s/";  //host, client key, tag

class Loggly {
public:
	void begin(HttpClient& http);
	bool log(const char * message, const size_t msgLen, const char * tag, const size_t tagLen);
private:
	HttpClient * _http;
};

#endif
