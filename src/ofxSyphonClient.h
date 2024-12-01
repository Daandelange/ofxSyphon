/*
 *  ofxSyphonServer.h
 *  syphonTest
 *
 *  Created by astellato,vade,bangnoise on 11/6/10.
 *
 *  http://syphon.v002.info/license.php
 */

#include "ofxSyphon.h"
#include "ofxSyphonNSObject.hpp"
#include "ofTexture.h"

class ofxSyphonClient {
	public:
	ofxSyphonClient();

    void setup();
    bool isSetup() const;
    bool isConnected() const;
    
    void set(const ofxSyphonServerDescription &_server);
    void set(const std::string &_serverName, const std::string &_appName);
    
    void setApplicationName(const std::string &_appName);
    void setServerName(const std::string &_serverName);
    
    const std::string& getApplicationName() const;
    const std::string& getServerName() const;
    
    void draw(float x, float y, float w, float h);
    void draw(float x, float y);
    void drawSubsection(float x, float y, float w, float h, float sx, float sy, float sw, float sh);
    void drawSubsection(float x, float y, float sx, float sy, float sw, float sh);

    float getWidth() const;
    float getHeight() const;
    bool isNewFrame() const;

    // check return from lockTexture() before proceeding, returns false is the client has no texture
    bool lockTexture();
    // Returns false if failed to unlock (rare)
    bool unlockTexture();
    
    // Returns true if the texture is available
    // calls lockTexture() then getTexture().bind()
    [[deprecated("Use getTexture().bind()")]]
    bool bind();
    // calls getTexture().unbind() then unlockTexture()
    [[deprecated("Use getTexture().unbind()")]]
    bool unbind();
    
    /*
     To use the texture with getTexture()
     you must surround it with lockTexture() and
     unlockTexture() functions */
    
    ofTexture& getTexture();
    
	protected:
	ofxSyphonNSObject mClient;
    ofxSyphonNSObject latestImage;
	ofTexture mTex;
	bool bSetup = false;
	bool bHasNewFrame;
    std::string appName, serverName;
};
