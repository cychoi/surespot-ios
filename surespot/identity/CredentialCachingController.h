//
//  CredentialCachingController.h
//  surespot
//
//  Created by Adam on 8/5/13.
//  Copyright (c) 2013 2fours. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EncryptionController.h"
#import "PublicKeys.h"
#import "SurespotConstants.h"

@interface CredentialCachingController : NSObject
+(CredentialCachingController*)sharedInstance;

@property (nonatomic, retain) NSMutableDictionary * sharedSecretsDict;
@property (nonatomic, retain) NSMutableDictionary * publicKeysDict;
@property (nonatomic, strong) NSMutableDictionary * latestVersionsDict;

@property (nonatomic, strong) NSOperationQueue * genSecretQueue;
@property (nonatomic, strong) NSOperationQueue * publicKeyQueue;
@property (atomic, strong) SurespotIdentity * loggedInIdentity;

-(void) getSharedSecretForOurVersion: (NSString *) ourVersion theirUsername: (NSString *) theirUsername theirVersion: (NSString *) theirVersion callback: (CallbackBlock) callback;
-(void) loginIdentity: (SurespotIdentity *) identity;


- (void) getLatestVersionForUsername: (NSString *) username callback:(CallbackStringBlock) callback;
-(void) clearUserData: (NSString *) username;
-(void) updateLatestVersionForUsername: (NSString *) username version: (NSString * ) version;

-(void) logout;
-(void) clearIdentityData:(NSString *) username;
-(void) cacheSharedSecret: secret forKey: sharedSecretKey;
-(void) saveLatestVersions;
@end
