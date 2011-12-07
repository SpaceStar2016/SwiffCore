/*
    SwiftMovie.h
    Copyright (c) 2011, musictheory.net, LLC.  All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
        * Redistributions of source code must retain the above copyright
          notice, this list of conditions and the following disclaimer.
        * Redistributions in binary form must reproduce the above copyright
          notice, this list of conditions and the following disclaimer in the
          documentation and/or other materials provided with the distribution.
        * Neither the name of musictheory.net, LLC nor the names of its contributors
          may be used to endorse or promote products derived from this software
          without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL MUSICTHEORY.NET, LLC BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#import <SwiftImport.h>
#import <SwiftBase.h>
#import <SwiftSpriteDefinition.h>

@class SwiftDynamicTextDefinition, SwiftFontDefinition,  SwiftShapeDefinition, 
       SwiftStaticTextDefinition,  SwiftSoundDefinition, SwiftScene;

@protocol SwiftMovieDecoder;


@interface SwiftMovie : SwiftSpriteDefinition {
@private
    NSData              *m_data;
    NSArray             *m_scenes;
    NSDictionary        *m_sceneNameToSceneMap;
    NSMutableDictionary *m_definitionMap;

    NSInteger            m_version;
    CGRect               m_stageRect;
    CGFloat              m_frameRate;
    SwiftColor           m_backgroundColor;
    
    id<SwiftMovieDecoder> m_decoder;
    BOOL m_decoder_movie_didDecodeFrame;
}

- (id) initWithData:(NSData *)data;

- (id) definitionWithLibraryID:(UInt16)libraryID;

- (void) decode:(id<SwiftMovieDecoder>)decoder;

- (SwiftFontDefinition        *) fontDefinitionWithLibraryID:(UInt16)libraryID;
- (SwiftShapeDefinition       *) shapeDefinitionWithLibraryID:(UInt16)libraryID;
- (SwiftSoundDefinition       *) soundDefinitionWithLibraryID:(UInt16)libraryID;
- (SwiftSpriteDefinition      *) spriteDefinitionWithLibraryID:(UInt16)libraryID;
- (SwiftStaticTextDefinition  *) staticTextDefinitionWithLibraryID:(UInt16)libraryID;
- (SwiftDynamicTextDefinition *) dynamicTextDefinitionWithLibraryID:(UInt16)libraryID;

- (SwiftScene *) sceneWithName:(NSString *)name;

@property (nonatomic, retain, readonly) NSArray *scenes;

@property (nonatomic, assign, readonly) NSInteger version;
@property (nonatomic, assign, readonly) CGFloat frameRate;
@property (nonatomic, assign, readonly) CGRect stageRect;

@property (nonatomic, assign, readonly) SwiftColor  backgroundColor;
@property (nonatomic, assign, readonly) SwiftColor *backgroundColorPointer;


@end


@protocol SwiftMovieDecoder <NSObject>
- (void) movie:(SwiftMovie *)movie didDecodeFrame:(SwiftFrame *)frame;
@end
