from codecs import decode
import struct


def bin_to_float(b):
    """Convert binary string to a float."""
    bf = int_to_bytes(int(b, 2), 8)  # 8 bytes needed for IEEE 754 binary64.
    return struct.unpack(">d", bf)[0]


def int_to_bytes(n, length):  # Helper function
    """Int/long to byte string.

    Python 3.2+ has a built-in int.to_bytes() method that could be used
    instead, but the following works in earlier versions including 2.x.
    """
    return decode("%%0%dx" % (length << 1) % n, "hex")[-length:]


def float_to_bin(value):  # For testing.
    """Convert float to 64-bit binary string."""
    [d] = struct.unpack(">Q", struct.pack(">d", value))
    return "{:064b}".format(d)


if __name__ == "__main__":
    for f in 0.0, 0.75:
        print("Test value: %f" % f)
        binary = float_to_bin(f)
        print(" float_to_bin: %r" % binary)
        floating_point = bin_to_float(binary)  # Round trip.
        print(" bin_to_float: %f\n" % floating_point)
