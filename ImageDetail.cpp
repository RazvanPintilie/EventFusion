class ImageDetail
{
private:
	int x;
	int y;
	int id;
	int rotateIndex;
public:
	ImageDetail(int x, int y, int id,int rotateIndex)
	{
		this->x = x;
		this->y = y;
		this->id = id;
		this->rotateIndex = rotateIndex;
	}
	ImageDetail() {};

	void setX(int x)
	{
		this->x = x;
	}

	void setY(int y)
	{
		this->y = y;
	}

	void setId(int id)
	{
		this->id = id;
	}
	void setRotateIndex(int rotateIndex) 
	{
		this->rotateIndex=rotateIndex;
	}
	int getX()
	{
		return x;
	}

	int getY()
	{
		return y;
	}

	int getId()
	{
		return id;
	}
	int getRotateIndex() {
		return rotateIndex;
	}
};