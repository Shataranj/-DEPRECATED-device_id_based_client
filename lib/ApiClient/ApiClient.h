#include "HttpClientWrapper.h"

class ApiClient {

public:

  String base_url;
  HttpClientWrapper http;

  ApiClient(String base_url);

  String createGame(String url, String device_id);
};