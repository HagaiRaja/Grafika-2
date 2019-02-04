//Dibuat Eka
#ifndef AIR_PLANE_H
#define AIR_PLANE_H

/* Kelas turunan dari objek untuk menggenerate makanan ikan */
class AirPlane {
public :
	/* Konstruktor untuk menentukan posisi makanan ikan ketika pertama kali dibangkitkan*/
	MakananIkan();
	MakananIkan(int _x, int _y);
	MakananIkan& operator=(const MakananIkan&);
	bool operator==(const MakananIkan&);

	/* Setter and Getter */
	int getIterasiGambar() const;
	void updateIterasiGambar();

private :
	int iterasiGambar;
};

#endif
