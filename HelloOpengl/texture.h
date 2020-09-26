#include "string"
class texture {
private:
	unsigned textureID;

public:
	void generateTexture(std::string file, unsigned format);
	void bindTexture();
	static void activeTexture(unsigned int texID);
	inline unsigned getTextureID (){
		return textureID;
	}
};