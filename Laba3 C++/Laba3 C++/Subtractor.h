#include "ExpressionEvaluator.h"

class Subtractor : public ExpressionEvaluator
{
public:
	inline virtual double calculate() override;
	inline void logToScreen() override;
	inline void logToFile(const std::string& filename) override;


};