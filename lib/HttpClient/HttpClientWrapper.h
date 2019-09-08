#include <HTTPClient.h>
#include <map>

class HttpClientWrapper{

public:
  String base_url;
  HTTPClient httpClient;

  String MakeGetCall(String url, std::map<String,String> headers);
};