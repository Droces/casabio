<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\CanonCustom;

use PHPExiftool\Driver\AbstractTag;

class PF2DisableMeteringModes extends AbstractTag
{

    protected $Id = 3;

    protected $Name = 'PF2DisableMeteringModes';

    protected $FullName = 'CanonCustom::PersonalFuncs';

    protected $GroupName = 'CanonCustom';

    protected $g0 = 'MakerNotes';

    protected $g1 = 'CanonCustom';

    protected $g2 = 'Camera';

    protected $Type = 'int16u';

    protected $Writable = true;

    protected $Description = 'PF2 Disable Metering Modes';

    protected $flag_Permanent = true;

}
