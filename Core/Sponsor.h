#pragma once

#include <string>

namespace Core
{
	class Sponsor
	{
	public:
		Sponsor() : adImage(0), fontWeight(0), fontType(0), fontScript(0), fontSize(0), backgroundColorSize(0), textColor(0),
					unknown1(0), unknown2(0), unknown3(0), unknown4(0), unknown5(0), unknown6(0), unknown7(0), 
					unknown8(0), unknown9(0), unknown10(0) {}
		~Sponsor() {}

		// getter
		std::string getName() { return name; }
		short getAdImage() { return adImage; }
		int getFontWeight() { return fontWeight; }
		int getFontType() { return fontType; }
		short getFontScript() { return fontScript; }
		short getFontSize() { return fontSize; }
		std::string getFont() { return font; }
		long getBackgroundColorSize() { return backgroundColorSize; }
		int getTextColor() { return textColor; }
		short getUnknown1() { return unknown1; }
		short getUnknown2() { return unknown2; }
		short getUnknown3() { return unknown3; }
		short getUnknown4() { return unknown4; }
		short getUnknown5() { return unknown5; }
		short getUnknown6() { return unknown6; }
		short getUnknown7() { return unknown7; }
		short getUnknown8() { return unknown8; }
		short getUnknown9() { return unknown9; }
		int getUnknown10() { return unknown10; }
		// setter
		void setName(const std::string name) { this->name = name; }
		void setAdImage(const short adImage) { this->adImage = adImage; }
		void setFontWeight(const int fontWeight) { this->fontWeight = fontWeight; }
		void setFontType(const int fontType) { this->fontType = fontType; }
		void setFontScript(const short fontScript) { this->fontScript = fontScript; }
		void setFontSize(const short fontSize) { this->fontSize = fontSize; }
		void setFont(const std::string font) { this->font = font; }
		void setBackgroundColorSize(const long backgroundColorSize) { this->backgroundColorSize = backgroundColorSize; }
		void setTextColor(const int textColor) { this->textColor = textColor; }
		void setUnknown1(const short unknown1) { this->unknown1 = unknown1; }
		void setUnknown2(const short unknown2) { this->unknown2 = unknown2; }
		void setUnknown3(const short unknown3) { this->unknown3 = unknown3; }
		void setUnknown4(const short unknown4) { this->unknown4 = unknown4; }
		void setUnknown5(const short unknown5) { this->unknown5 = unknown5; }
		void setUnknown6(const short unknown6) { this->unknown6 = unknown6; }
		void setUnknown7(const short unknown7) { this->unknown7 = unknown7; }
		void setUnknown8(const short unknown8) { this->unknown8 = unknown8; }
		void setUnknown9(const short unknown9) { this->unknown9 = unknown9; }
		void setUnknown10(const int unknown10) { this->unknown10 = unknown10; }
	private:
		std::string name;
		short adImage = 0;
		int fontWeight = 0;		//400..Standard, 700...fett
		int fontType = 0;		//0..normal, 255 kursiv
		short fontScript = 0;	//westeuropäisch, kyrilisch, griechisch, ...
		short fontSize = 0;
		std::string font;
		long backgroundColorSize = 0;		// .... xxxx xxxx xxxx xxxx background color
											// xxxx .... .... .... .... size
		int textColor = 0;
		short unknown1 = 0;
		short unknown2 = 0;
		short unknown3 = 0;
		short unknown4 = 0;
		short unknown5 = 0;
		short unknown6 = 0;
		short unknown7 = 0;
		short unknown8 = 0;
		short unknown9 = 0;
		int unknown10 = 0;
	};
}