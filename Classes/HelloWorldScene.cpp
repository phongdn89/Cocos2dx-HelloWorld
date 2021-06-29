/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"

USING_NS_CC;

Scene *HelloWorld::createScene() {
    return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init() {
    //////////////////////////////
    // 1. super init first
    if (!Scene::init()) {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize(); // lay ve kich thuoc man hinh
    Vec2 origin = Director::getInstance()->getVisibleOrigin(); // lay ve toa do goc
    auto backgroundSprite = Sprite::create("background.png");
    backgroundSprite->setContentSize(Size(visibleSize.width, visibleSize.height));
    backgroundSprite->setPosition(origin.x + visibleSize.width / 2,
                                  origin.y + visibleSize.height / 2);
    addChild(backgroundSprite);

//    auto luckkySprite = Sprite::create("lucky_wheel_2.png");
//    luckkySprite->setPosition(backgroundSprite->getContentSize().width/2,backgroundSprite->getContentSize().height/2);
//    luckkySprite->setContentSize(Size(backgroundSprite->getContentSize().width,backgroundSprite->getContentSize().width));
//    backgroundSprite->addChild(luckkySprite);
//
//    float a = (origin.y+visibleSize.height-luckkySprite->getContentSize().height)/2;
//
//    auto logoSprite = Sprite::create("logo_studio.png");
//    logoSprite->setPosition(backgroundSprite->getContentSize().width/2,a/2);
//    logoSprite->setContentSize(Size(a*(384.0/567.0),a));
//    backgroundSprite->addChild(logoSprite);


//vong quay 2
    //auto wheelSprite = Sprite::create("ls_screen_in.png");
    //wheelSprite->setPosition(backgroundSprite->getContentSize().width / 2,
                             //backgroundSprite->getContentSize().height / 2);
    //wheelSprite->setContentSize(Size(backgroundSprite->getContentSize().width,
                                     //backgroundSprite->getContentSize().width));
    //backgroundSprite->addChild(wheelSprite);

    //auto donutSprite = Sprite::create("ls_screen_out.png");
    //donutSprite->setPosition(backgroundSprite->getContentSize().width / 2,
                             //backgroundSprite->getContentSize().height / 2);
    //donutSprite->setContentSize(Size(backgroundSprite->getContentSize().width,
                                     //backgroundSprite->getContentSize().width));
    //backgroundSprite->addChild(donutSprite);
    //wheelSprite->runAction(RepeatForever::create(RotateBy::create(1,360)));


    /**
     * Bài 2 : move
     */
    auto redSprite = Sprite::create("box_red_normal.png");
    redSprite->setPosition(redSprite->getContentSize().width/2,redSprite->getContentSize().height/2);
    backgroundSprite->addChild(redSprite);

    auto yellowSprite = Sprite::create("box_yellow_normal.png");
    yellowSprite->setPosition(backgroundSprite->getContentSize().width/2,backgroundSprite->getContentSize().height-yellowSprite->getContentSize().height/2);
    backgroundSprite->addChild(yellowSprite);
    yellowSprite->setLocalZOrder(10);

    auto greenSprite = Sprite::create("box_green_normal.png");
    greenSprite->setPosition(backgroundSprite->getContentSize().width/2,backgroundSprite->getContentSize().height/2);
    backgroundSprite->addChild(greenSprite);

//    auto moveRedToCenter = MoveTo::create(3,Vec2(backgroundSprite->getContentSize().width/2,backgroundSprite->getContentSize().height/2)); dùng nhiều
//    yellowSprite->runAction(moveRedToCenter);
//    redSprite->runAction(moveRedToCenter->clone());

//auto moveToCenterMoveBy = MoveBy::create(3,Vec2(0,backgroundSprite->getContentSize().height/2-(backgroundSprite->getContentSize().height-yellowSprite->getContentSize().height/2)));
//auto moveToCenterMoveBy = MoveBy::create(3,Vec2(0,-30));
//yellowSprite->runAction(moveToCenterMoveBy);

//    greenSprite->setRotation(60);
////    auto rotate360Action = RotateBy::create(5,360); dùng nhiều
//    auto rotate360Action = RotateTo::create(5,360);
//    greenSprite->runAction(rotate360Action);

//    auto scaleTo = ScaleTo::create(5,3.0);
//    auto scaleTo = ScaleTo::create(2,0.1);
//    auto scaleTo = ScaleTo::create(2,0.8,0.5);
//    greenSprite->runAction(scaleTo);

//// Thằng vàng chạy xuống giữa, sau đó scale 1 nửa, sau đó chạy xuống góc dưới trái
//    auto moveRedToCenter = MoveTo::create(2,Vec2(backgroundSprite->getContentSize().width/2,backgroundSprite->getContentSize().height/2));
//    auto scale50 = ScaleTo::create(2,0.5);
//    auto moveToConner = MoveTo::create(2,Vec2(redSprite->getContentSize().width/2,redSprite->getContentSize().height/2));
//    auto continues = Sequence::create(moveRedToCenter,scale50,moveToConner, nullptr);
//    yellowSprite->runAction(continues);

////// Thằng vàng chạy xuống giữa đồng thời scale 1 nửa
//    auto moveRedToCenter = MoveTo::create(2,Vec2(backgroundSprite->getContentSize().width/2,backgroundSprite->getContentSize().height/2));
//    auto scale50 = ScaleTo::create(2,0.5);
//    auto continues = Spawn::create(moveRedToCenter,scale50, nullptr);
//    yellowSprite->runAction(continues);

    auto moveToCenterDelay = MoveTo::create(4,Vec2(backgroundSprite->getContentSize().width/2,backgroundSprite->getContentSize().width/2));
    auto delay = DelayTime::create(2);
    auto scaleDown = ScaleTo::create(1,0.5);
    auto delay1 = DelayTime::create(1);
    auto scaleUp = ScaleTo::create(1,1);
    auto sequence = Sequence::create(moveToCenterDelay,delay,scaleDown,delay1,scaleUp, nullptr);
    yellowSprite->runAction(sequence);


    return true;
}

