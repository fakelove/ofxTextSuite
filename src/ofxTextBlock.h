/***********************************************************************

 Copyright (c) 2009, Luke Malcolm, www.lukemalcolm.com

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.

 ***********************************************************************/

#ifndef OFXTEXTBLOCK_H
#define OFXTEXTBLOCK_H

#include "ofMain.h"
#include <iterator>

class wordBlock {
    public:
        string          rawWord;
        float           width;
        float           height;
        ofColor         color;
        ofTrueTypeFont * ttf = NULL;

        void draw( int x_, int y_ ){
            if( ttf != NULL ) ttf->drawString(rawWord.c_str(), x_, y_);
        }
};


class lineBlock {
    public:
        vector<int>   wordsID;
        float   width;
        float   height;
};


enum TextBlockAlignment {
    OF_TEXT_ALIGN_LEFT,
    OF_TEXT_ALIGN_RIGHT,
    OF_TEXT_ALIGN_JUSTIFIED,
    OF_TEXT_ALIGN_CENTER
};

enum TextFontFamilly {
    FONT_BOLD,
    FONT_BOLD_ITALIC,
    FONT_LIGHT,
    FONT_LIGHT_ITALIC,
    FONT_MEDIUM,
    FONT_MEDIUM_ITALIC,
    FONT_REGULAR,
    FONT_REGULAR_ITALIC,
    FONT_ULTRALIGHT,
    FONT_ULTRALIGHT_ITALIC
};


class ofxTextBlock
{
    public:
        ofxTextBlock();
        virtual ~ofxTextBlock();

        string          rawText;
        ofTrueTypeFont  defaultFont;


        ofTrueTypeFont*  font_bold;
        ofTrueTypeFont*  font_bold_italic;
        ofTrueTypeFont*  font_light;
        ofTrueTypeFont*  font_light_italic;
        ofTrueTypeFont*  font_medium;
        ofTrueTypeFont*  font_medium_italic;
        ofTrueTypeFont*  font_regular;
        ofTrueTypeFont*  font_regular_italic;
        ofTrueTypeFont*  font_ultralight;
        ofTrueTypeFont*  font_ultralight_italic;

        ofTrueTypeFont * getFontForWord( string word_ );

        wordBlock       blankSpaceWord;
        float           scale;

        vector<wordBlock>   words;
        vector<lineBlock>   lines;

        void    init(string fontLocation, float fontSize);

        void    setText(string _inputText);

        int     wrapTextX(float lineWidth);                 //Returns the number of lines it formed.
        void    wrapTextArea(float rWidth, float rHeight);
        bool    wrapTextForceLines(int linesN);

        void    setLineHeight(float lineHeight);
        void    setColor(int r, int g, int b, int a);

        void    draw(float x, float y);                    //Draws left align.
        void    drawLeft(float x, float y);
        void    drawRight(float x, float y);
        void    drawCenter(float x, float y);
        void    drawJustified(float x, float y, float boxWidth);

        void    forceScale(float _scale);
        void    loadFontFamilly( string fontLocation, int font_family, int font_size );

        float   getWidth();
        float   getHeight();

        bool isMetaTag( string str_, string tag_ );
        bool isMetaTagStart( string & str_ );
        bool isMetaTagEnd( string & str_ );

    protected:

        void    _loadWords();

        void    _trimLineSpaces();
        float   _getWidthOfWords();
        int     _getLinedWords();

    private:
};

#endif // OFXTEXTBLOCK_H
