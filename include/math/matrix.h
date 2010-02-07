/*
 *
 *		The Poleaxe Graphics and Windowing system.
 *
 * Jeff Shoulders and Robert Butler
 * hx86 working group
 * loliniel@gmail.com
 * lighth7015@gmail.com
 *
 *	(c) 2010
 *
 */




 typedef class Matrix
{
	private:
		float m[16];
	public:
		Matrix()
		{}

		~Matrix()
		{}

		void Set(int x, int y, float v)
		{
			m[(y*4)+x] = v;
		}

		void Set(int x, float v)
		{
			m[x] = v;
		}

		float *Get()
		{
			return m;
		}

		void Set(float m1[16])
		{
			for(int i=0; i<16; i++)
                m[i] = m1[i];
		}

		inline void operator *= (int s)
		{
			for(int i=0; i<16; i++)
				m[i] *= s;
		}

		void SetIdentity()
		{
			SetZero();
			m[0] = 1.0f;
            m[5] = 1.0f;
			m[10] = 1.0f;
			m[15] = 1.0f;
		}

		void SetZero()
		{
			for(int i=0; i<16; i++)
				m[i] = 0.0f;
		}

		float operator[](int r)
		{
			return m[r];
		}

		Matrix operator +(Matrix m1)
		{
			Matrix r;
			r.SetZero();

			for(int i=0; i<16; i++)
				r.Set(i, (m[i] + m1[i]));

			return r;
		}

} Matrix;
