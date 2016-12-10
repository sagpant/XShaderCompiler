
// Buffer Objects Test
// 10/12/2016

cbuffer Settings : register(b0)
{
	uint3 groupSize;
};

Buffer<float4> inBuffer : register(t0);

RWBuffer<float4> outBuffer : register(u0);


[numthreads(1, 1, 1)]
void CS(uint3 groupID : SV_GroupID)
{
	// Get global index
	uint i = groupID.z*groupSize.x*groupSize.y + groupID.y*groupSize.x + groupID.x;
	
	// Flip components
	outBuffer[i] = inBuffer[i].wzxy;
}
