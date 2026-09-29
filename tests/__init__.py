# Copyright © 2014 CCP ehf.

# Basic smoketests to make sure nothing crashes when called.

import unittest2
import inputmethod


class TestIME(unittest2.TestCase):
    def setUp(self):
        self.ime = inputmethod.Ime()

    def tearDown(self):
        del self.ime

    def testAssociateContext(self):
        ret = self.ime.AssociateContext(0)
        self.assertIsNone(ret)

    def testBackspace(self):
        ret = self.ime.Backspace(13)
        self.assertIsNone(ret)

    def testGetCompositionString(self):
        ret = self.ime.GetCompositionString(0)
        self.assertEqual(ret, {})

    def testGetConversionStatus(self):
        ret = self.ime.GetConversionStatus()
        self.assertListEqual(ret, [0, 0])

    def testGetKeyboardLayout(self):
        ret = self.ime.GetKeyboardLayout()
        self.assertIsInstance(ret, int)

    def testGetOpenStatus(self):
        ret = self.ime.GetOpenStatus()
        self.assertEqual(ret, 0)

    def testGetRefCounts(self):
        ret = self.ime.GetRefCounts()
        self.assertTupleEqual(ret, (2, 1))

    def testIsIME(self):
        ret = self.ime.IsIME()
        self.assertEqual(ret, 1)

    def testNotifyIME(self):
        ret = self.ime.NotifyIME(0, 0)
        self.assertEqual(ret, 0)

    def testSetHWND(self):
        ret = self.ime.SetHWND(0)
        self.assertIsNone(ret)

    def testSetOpenStatus(self):
        ret = self.ime.SetOpenStatus(0)
        self.assertEqual(ret, 0)

    def testSimulateHotKey(self):
        ret = self.ime.SimulateHotKey(0)
        self.assertEqual(ret, 0)