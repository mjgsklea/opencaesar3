// This file is part of openCaesar3.
//
// openCaesar3 is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// openCaesar3 is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with openCaesar3.  If not, see <http://www.gnu.org/licenses/>.


#ifndef __OPENCAESAR3_GUILABEL_H_INCLUDE_
#define __OPENCAESAR3_GUILABEL_H_INCLUDE_

#include "oc3_gui_widget.hpp"
#include "oc3_picture.hpp"
#include "oc3_signals.hpp"

class Label : public Widget
{
public:
  typedef enum { bgWhite=0, bgBlack, bgBrown, bgSmBrown, bgNone, bgWhiteFrame, bgBlackFrame } BackgroundMode;
  //! constructor
  Label( Widget* parent );

  Label( Widget* parent, const Rect& rectangle, const std::string& text="", bool border=false,
         BackgroundMode background = bgNone, int id=-1);

  //! destructor
  virtual ~Label();

  //! draws the element and its children
  virtual void draw( GfxEngine& painter );

  virtual void setPadding( const Rect& margin );

  //! Get the font which is used right now for drawing
  virtual Font getFont() const;

  //! Sets whether to draw the background
  virtual void setBackgroundMode( BackgroundMode mode );

  virtual void beforeDraw( GfxEngine& painter );

  //! Return background draw
  virtual BackgroundMode getBackgroundMode() const;

  virtual bool isBorderVisible() const;

  //! Sets whether to draw the border
  virtual void setBorderVisible(bool draw);

  //! Set whether the text in this label should be clipped if it goes outside bounds
  virtual void setTextRestrainedInside(bool restrainedInside);

  //! Checks if the text in this label should be clipped if it goes outside bounds
  virtual bool isTextRestrainedInside() const;

  //! Enables or disables word wrap for using the static text as
  //! multiline text control.
  virtual void setWordWrap(bool enable);

  //! Checks if word wrap is enabled
  virtual bool isWordWrapEnabled() const;

  //! Sets the new caption of this element.
  virtual void setText(const std::string& text);

  //! Returns the height of the text in pixels when it is drawn.
  virtual int getTextHeight() const;

  //! Returns the width of the current text, in the current font
  virtual int getTextWidth() const;

  //! Set whether the string should be interpreted as right-to-left (RTL) text
  /** \note This component does not implement the Unicode bidi standard, the
  text of the component should be already RTL if you call this. The
  main difference when RTL is enabled is that the linebreaks for multiline
  elements are performed starting from the end.
  */
  virtual void setRightToLeft(bool rtl);

  //! Checks if the text should be interpreted as right-to-left text
  virtual bool isRightToLeft() const;

  virtual void setPrefixText( const std::string& prefix );

  virtual void setBackgroundPicture( const Picture& picture, const Point& offset=Point() );

  virtual void setFont( const Font& font );

  virtual void setTextAlignment( TypeAlign horizontal, TypeAlign vertical );

  virtual void setLineIntervalOffset( const int offset );

  virtual void setupUI( const VariantMap &ui );
    
oc3_signals public:
  virtual Signal0<>& onClicked();

protected:
  virtual void _resizeEvent();
  virtual void _updateTexture( GfxEngine& painter );
  PictureRef& getPicture();
  PictureRef& getTextPicture();

private:

  class Impl;
  std::auto_ptr< Impl > _d;   
};

#endif
