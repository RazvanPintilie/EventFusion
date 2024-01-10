class ImageDetail {
private:
	int x;
	int y;
	int id;
public:
	ImageDetail(int x, int y, int id) {
		this->x = x;
		this->y = y;
		this->id = id;
	}
	ImageDetail() {};
	void setX(int x) {
		this->x = x;
	}
	void setY(int) {
		this->y = y;
	}
	void setId(int id) {
		this->id = id;
	}

	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	int getId() {
		return id;
	}


};