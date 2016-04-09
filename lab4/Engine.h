
#ifndef ENGINE_H_
#define ENGINE_H_

enum Color {Black, White, Sliver, Grey, Red, Blue};
class Engine
{
public:
	Engine(int nc);		// Conversion Constructor
	void Start();	//Start the engine
	void Stop();		//Stop the engine
	int getNumCylinder() const;
private:
	int numCylinder;		//number of cylinders in the engine

};

#endif /* ENGINE_H_ */
