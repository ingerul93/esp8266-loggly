#ifndef __LOGGLY_H__
#define __LOGGLY_H__

#include <ESP8266HTTPClient>

#ifndef LOGGLY_HOST
	#define LOGGLY_HOST "logs-01.loggly.com"
#endif

#ifndef LOGGLY_KEY
	#define LOGGLY_KEY "client_key"
#endif

static const char * LOGGLY_URL_FORMAT = "http://%s/inputs/%s/tag/%s/";  //host, client key, tag

class Loggly {
public:
	void begin(HTTPClient& http);
	bool log(const char * message, const size_t msgLen, const char * tag, const size_t tagLen);
private:
	HTTPClient * _http;
};

#endif
