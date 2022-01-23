
double lerp(double start, double end, double alpha)
{
	return (end - start) * alpha + start;
}

double invlerp(double start, double end, double value)
{
	return (value / (end - start));
}

double remap(double input_a, double input_b, double out_a, double out_b, double value)
{
	return lerp(out_a, out_b, invlerp(input_a, input_b, value));
}
