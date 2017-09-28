/* LCM type definition class file
 * This file was automatically generated by lcm-gen
 * DO NOT MODIFY BY HAND!!!!
 */

package sampling;
 
import java.io.*;
import java.util.*;
import lcm.lcm.*;
 
public final class all_regions implements lcm.lcm.LCMEncodable
{
    public int num_region;
    public sampling.region_data regions[];
 
    public all_regions()
    {
    }
 
    public static final long LCM_FINGERPRINT;
    public static final long LCM_FINGERPRINT_BASE = 0x5116c004e56bc0afL;
 
    static {
        LCM_FINGERPRINT = _hashRecursive(new ArrayList<Class<?>>());
    }
 
    public static long _hashRecursive(ArrayList<Class<?>> classes)
    {
        if (classes.contains(sampling.all_regions.class))
            return 0L;
 
        classes.add(sampling.all_regions.class);
        long hash = LCM_FINGERPRINT_BASE
             + sampling.region_data._hashRecursive(classes)
            ;
        classes.remove(classes.size() - 1);
        return (hash<<1) + ((hash>>63)&1);
    }
 
    public void encode(DataOutput outs) throws IOException
    {
        outs.writeLong(LCM_FINGERPRINT);
        _encodeRecursive(outs);
    }
 
    public void _encodeRecursive(DataOutput outs) throws IOException
    {
        outs.writeInt(this.num_region); 
 
        for (int a = 0; a < this.num_region; a++) {
            this.regions[a]._encodeRecursive(outs); 
        }
 
    }
 
    public all_regions(byte[] data) throws IOException
    {
        this(new LCMDataInputStream(data));
    }
 
    public all_regions(DataInput ins) throws IOException
    {
        if (ins.readLong() != LCM_FINGERPRINT)
            throw new IOException("LCM Decode error: bad fingerprint");
 
        _decodeRecursive(ins);
    }
 
    public static sampling.all_regions _decodeRecursiveFactory(DataInput ins) throws IOException
    {
        sampling.all_regions o = new sampling.all_regions();
        o._decodeRecursive(ins);
        return o;
    }
 
    public void _decodeRecursive(DataInput ins) throws IOException
    {
        this.num_region = ins.readInt();
 
        this.regions = new sampling.region_data[(int) num_region];
        for (int a = 0; a < this.num_region; a++) {
            this.regions[a] = sampling.region_data._decodeRecursiveFactory(ins);
        }
 
    }
 
    public sampling.all_regions copy()
    {
        sampling.all_regions outobj = new sampling.all_regions();
        outobj.num_region = this.num_region;
 
        outobj.regions = new sampling.region_data[(int) num_region];
        for (int a = 0; a < this.num_region; a++) {
            outobj.regions[a] = this.regions[a].copy();
        }
 
        return outobj;
    }
 
}

