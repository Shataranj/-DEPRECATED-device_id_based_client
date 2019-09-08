#include "ApiClient.h"

ApiClient::ApiClient(String base_url){
  this->base_url = base_url;
}

String ApiClient::createGame(String url, String device_id){
  std::map<String,String> headers;
  headers.insert({"device-id","y"});
  String response = http.MakeGetCall(base_url+url,headers);
  return response;
}