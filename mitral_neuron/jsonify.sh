sed -i '/^$/d' $1
sed -i 's/$/,/' $1
sed -i '1i{\n  \"mitral_neuron_cell\": \"0\",\n  \"data\": {\n   \"time\": [\n' $1 
sed -i 's/voltage,/ \n],\n  \"voltage\": [\n/' $1
sed -ie "\$a]\n },\n \"units\": \"mV\",\n \"name\": \"neuron\"\n}" $1
sed -i '/^ *$/d' $1
sed -i ':a;N;$!ba;s/,\n]/\n]/g' $1
