"""LCM type definitions
This file automatically generated by lcm.
DO NOT MODIFY BY HAND!!!!
"""

try:
    import cStringIO.StringIO as BytesIO
except ImportError:
    from io import BytesIO
import struct

class path_data(object):
    __slots__ = ["num_state", "state_x", "state_y"]

    __typenames__ = ["int32_t", "double", "double"]

    __dimensions__ = [None, ["num_state"], ["num_state"]]

    def __init__(self):
        self.num_state = 0
        self.state_x = []
        self.state_y = []

    def encode(self):
        buf = BytesIO()
        buf.write(path_data._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf):
        buf.write(struct.pack(">i", self.num_state))
        buf.write(struct.pack('>%dd' % self.num_state, *self.state_x[:self.num_state]))
        buf.write(struct.pack('>%dd' % self.num_state, *self.state_y[:self.num_state]))

    def decode(data):
        if hasattr(data, 'read'):
            buf = data
        else:
            buf = BytesIO(data)
        if buf.read(8) != path_data._get_packed_fingerprint():
            raise ValueError("Decode error")
        return path_data._decode_one(buf)
    decode = staticmethod(decode)

    def _decode_one(buf):
        self = path_data()
        self.num_state = struct.unpack(">i", buf.read(4))[0]
        self.state_x = struct.unpack('>%dd' % self.num_state, buf.read(self.num_state * 8))
        self.state_y = struct.unpack('>%dd' % self.num_state, buf.read(self.num_state * 8))
        return self
    _decode_one = staticmethod(_decode_one)

    _hash = None
    def _get_hash_recursive(parents):
        if path_data in parents: return 0
        tmphash = (0x6655b004fa7976de) & 0xffffffffffffffff
        tmphash  = (((tmphash<<1)&0xffffffffffffffff) + (tmphash>>63)) & 0xffffffffffffffff
        return tmphash
    _get_hash_recursive = staticmethod(_get_hash_recursive)
    _packed_fingerprint = None

    def _get_packed_fingerprint():
        if path_data._packed_fingerprint is None:
            path_data._packed_fingerprint = struct.pack(">Q", path_data._get_hash_recursive([]))
        return path_data._packed_fingerprint
    _get_packed_fingerprint = staticmethod(_get_packed_fingerprint)

