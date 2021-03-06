//
//  REMHTTPSessionManager.h
//  Maris
//
//  Created by Scott Petit on 3/29/14.
//  Copyright (c) 2014 Scott Petit. All rights reserved.
//

#import "AFHTTPSessionManager.h"
#import "REMCompoundResponseSerializer.h"

@interface REMHTTPSessionManager : AFHTTPSessionManager

@property (nonatomic, strong) REMCompoundResponseSerializer *responseSerializer;

/**
 *  Creates and runs an `NSURLSessionDataTask` with a `GET` request.
 *
 *  @param URLString  The URL string used to create the request URL.
 *  @param parameters The parameters to be encoded according to the client request serializer.
 *  @param modelClass Your MTLModel subclass that also conforms to MTLJSONSerializing. Can be NIL but if so will only return a JSON Dictionary for the given keyPath.
 *  @param keyPath    The root keyPath of the model object.  Can be NIL.
 *  @param success    A block object to be executed when the task finishes successfully. This block has no return value and takes two arguments: the data task, and the response object created by the client response serializer.
 *  @param failure    A block object to be executed when the task finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes a two arguments: the data task and the error describing the network or parsing error that occurred.

 *
 *  @return The created and resumed NSURLSessionDataTask
 */
- (NSURLSessionDataTask *)GET:(NSString *)URLString
                   parameters:(NSDictionary *)parameters
                   modelClass:(Class)modelClass
                      keyPath:(NSString *)keyPath
                      success:(void (^)(NSURLSessionDataTask *task, id responseObject))success
                      failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure;

- (NSURLSessionDataTask *)HEAD:(NSString *)URLString
                    parameters:(NSDictionary *)parameters
                    modelClass:(Class)modelClass
                       keyPath:(NSString *)keyPath
                       success:(void (^)(NSURLSessionDataTask *task))success
                       failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure;

- (NSURLSessionDataTask *)POST:(NSString *)URLString
                    parameters:(NSDictionary *)parameters
                    modelClass:(Class)modelClass
                       keyPath:(NSString *)keyPath
                       success:(void (^)(NSURLSessionDataTask *task, id responseObject))success
                       failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure;

- (NSURLSessionDataTask *)POST:(NSString *)URLString
                    parameters:(NSDictionary *)parameters
     constructingBodyWithBlock:(void (^)(id <AFMultipartFormData> formData))block
                    modelClass:(Class)modelClass
                       keyPath:(NSString *)keyPath
                       success:(void (^)(NSURLSessionDataTask *task, id responseObject))success
                       failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure;

- (NSURLSessionDataTask *)PUT:(NSString *)URLString
                   parameters:(NSDictionary *)parameters
                   modelClass:(Class)modelClass
                      keyPath:(NSString *)keyPath
                      success:(void (^)(NSURLSessionDataTask *task, id responseObject))success
                      failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure;

- (NSURLSessionDataTask *)PATCH:(NSString *)URLString
                     parameters:(NSDictionary *)parameters
                     modelClass:(Class)modelClass
                        keyPath:(NSString *)keyPath
                        success:(void (^)(NSURLSessionDataTask *task, id responseObject))success
                        failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure;

- (NSURLSessionDataTask *)DELETE:(NSString *)URLString
                      parameters:(NSDictionary *)parameters
                      modelClass:(Class)modelClass
                         keyPath:(NSString *)keyPath
                         success:(void (^)(NSURLSessionDataTask *task, id responseObject))success
                         failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure;

@end
