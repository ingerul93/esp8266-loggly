#include "loggly.h"


void Loggly::begin(HTTPClient& client) {
	this->_http = &client;
}


bool Loggly::log(const char * message, const size_t msgLen, const char * tag, const size_t tagLen) {
	char url[256];
	sprintf(url, LOGGLY_URL_FORMAT, LOGGLY_HOST, LOGGLY_KEY, tag);
	_http->begin(url);
	_http->addHeader("content-type", "text/plain");
	_http->sendRequest("POST", message, msgLen);
	_http->end();
	return false;
}
