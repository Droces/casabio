<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\Qualcomm;

use PHPExiftool\Driver\AbstractTag;

class AWBBlueGainRef1 extends AbstractTag
{

    protected $Id = 'awb_blue_gain_ref1';

    protected $Name = 'AWBBlueGainRef1';

    protected $FullName = 'Qualcomm::Main';

    protected $GroupName = 'Qualcomm';

    protected $g0 = 'MakerNotes';

    protected $g1 = 'Qualcomm';

    protected $g2 = 'Camera';

    protected $Type = '?';

    protected $Writable = false;

    protected $Description = 'AWB Blue Gain Ref1';

    protected $flag_Permanent = true;

}
