#include "iostream"
#include "HttpClientWrapper.h"

String HttpClientWrapper::MakeGetCall(String url, std::map<String,String> headers){
    String response;
    for (std::map<String, String>::iterator header=headers.begin(); header!=headers.end(); ++header){
        httpClient.addHeader(header->first,header->second);
    }

    httpClient.begin(url);
    int httpCode = httpClient.GET();
    if (httpCode > 0) {
        response = httpClient.getString();
    } else {
        // Throw execption 
    }
    httpClient.end();
    return response;
}