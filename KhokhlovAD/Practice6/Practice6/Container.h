#ifndef  _CONTAINER
#define  _CONTAINER

enum TContainerExeption { cntINDOUTOFRANGE, cntVALOUTOFRANGE };
template <class TELEM>
class TContainer
{
protected:
	TELEM* elem; // ������ �������� ���������
	int size; // ������ �������
	int count; // �-�� ������� �������� ���������
	const static int sizestep = 10; // ��� ����������� ������� �������
public:
	TContainer(int _size = 50);
	TContainer(const TContainer& _cnt);
	~TContainer();

	const int getSize()const { return size; }
	const int& �ount() const { return count; }
	const int& Sizestep() const { return sizestep; }

	void Add(TELEM _elm);
	void Del(TELEM _elm);
	void Del(unsigned int index);// ������� ������� �� ��� ������

	TELEM& operator[](int index);
	TELEM& operator[](const TELEM& _elm);
	const TContainer& operator=(const TContainer& _cnt);
	TContainer operator+(const TContainer& _cnt);
	TContainer operator*(const TContainer& _cnt);
	TContainer operator-(const TContainer& _cnt);
protected:
	void resize(int dsize = 0);
	int _find(const TELEM& _elm) const;
};

template<class TELEM>
TContainer<TELEM>::TContainer(int _size)
{
	size = _size;
	count = 0;
	elem = new TELEM[size];
};

template<class TELEM>
TContainer<TELEM>::TContainer(const TContainer& _cnt)
{
	size = _cnt.size;
	count = _cnt.count;
	elem = new TELEM[size];
	for (int i = 0; i < count; i++)
		elem[i] = _cnt.elem[i];
};

template<class TELEM>
TContainer<TELEM>::~TContainer()
{
	if (size > 0) {
		delete[] elem;
		elem = 0;
		count = 0;
		size = 0;
	}
};

template<class TELEM>
void TContainer<TELEM>::Add(TELEM _elm)
{
	if (_find(_elm) == -1)
	{
		if (size == count) resize();
		elem[count++] = _elm;
	}
};// �������� �������

template<class TELEM>
void TContainer<TELEM>::Del(TELEM _elm)
{
	Del(_find(_elm)); // ������� ��������� �������
};// ������� ������� �� ��� ��������

template<class TELEM>
void TContainer<TELEM>::Del(unsigned int index)
{
	if (index > -1 && index < count)
		for (int i = index; i < count - 1; i++)
			elem[i] = elem[i + 1];
	count--;
};// ������� ������� �� ��� ������

template<class TELEM>
TELEM& TContainer<TELEM>::operator[](int index)
{
	if (index < 0 || index >= count)
	{
		TContainerExeption expt = cntINDOUTOFRANGE;
		throw expt;
	}
	return elem[index]; // ��� ������������� ��������
};// ���������� �� ������

template<class TELEM>
TELEM& TContainer<TELEM>::operator[](const TELEM& _elm)
{
	int index;
	if ((index = _find(_elm)) == -1)
	{
		TContainerExeption expt = cntVALOUTOFRANGE;
		throw expt;
	}
	return elem[index]; // ��� ������������� ��������
};// ���������� ������������


template <class TELEM>
const TContainer<TELEM>& TContainer<TELEM>::operator=(const TContainer<TELEM>& _cnt)
{
	if (this != &_cnt) {
		delete[] elem;;
		size = _cnt.size;
		count = _cnt.count;
		elem = new TELEM[size];
		for (int i = 0; i < count; i++)
			elem[i] = _cnt.elem[i];
	}
	return *this;
};//������������ 

template <class TELEM>
TContainer<TELEM> TContainer<TELEM>::operator+(const TContainer& _cnt)
{
	int i;
	TContainer<TELEM> tmp(count + _cnt.count + sizestep);
	for (i = 0; i < count; i++)
		tmp.elem[i] = elem[i];
	tmp.count = count;
	for (i = 0; i < _cnt.count; i++)
		tmp.Add(_cnt.elem[i]);
	return tmp;
};// �����������

template <class TELEM>
TContainer<TELEM> TContainer<TELEM>::operator*(const TContainer& _cnt)
{
	int i;
	int ss = count;
	if (ss < _cnt.count) ss = _cnt.count;
	TContainer<TELEM> tmp(ss + sizestep);
	tmp.count = 0;
	for (i = 0; i < count; i++)
		if (_cnt._find(elem[i]) != -1) tmp.elem[tmp.count++] =
			elem[i];
	return tmp;
};// �����������

template <class TELEM>
TContainer<TELEM> TContainer<TELEM>::operator-(const TContainer& _cnt)
{
	int i;
	TContainer<TELEM> tmp(count + sizestep);
	tmp.count = 0;
	for (i = 0; i < count; i++)
		if (_cnt._find(elem[i]) == -1) tmp.elem[tmp.count++] =
			elem[i];
	return tmp;
};// ��������

template <class TELEM>
void TContainer<TELEM>::resize(int dsize)
{
	if (dsize == 0) dsize = sizestep;
	size += dsize;
	TELEM* tmp = new TELEM[size];
	for (int i = 0; i < count; i++)
		tmp[i] = elem[i];
	delete[] elem;
	elem = tmp;
};// ��������� �����

template <class TELEM>
int TContainer<TELEM>::_find(const TELEM& _elm) const //����� �������
{
	int nom = -1;
	int i = 0;
	while (i < count && nom == -1)
		if (elem[i] == _elm) nom = i; else i++;
	return nom;
}
#endif