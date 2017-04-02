<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\XMPPur;

use PHPExiftool\Driver\AbstractTag;

class ReuseProhibited extends AbstractTag
{

    protected $Id = 'reuseProhibited';

    protected $Name = 'ReuseProhibited';

    protected $FullName = 'XMP::pur';

    protected $GroupName = 'XMP-pur';

    protected $g0 = 'XMP';

    protected $g1 = 'XMP-pur';

    protected $g2 = 'Document';

    protected $Type = 'boolean';

    protected $Writable = true;

    protected $Description = 'Reuse Prohibited';

    protected $flag_Avoid = true;

}
